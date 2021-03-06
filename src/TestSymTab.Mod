MODULE TestSymTab;

IMPORT
  Object, Out, Err, IO, IO:StdChannels, URI,
  CfgData := Config, Config:Section:Options, OOC:Config, OOC:Config:Pragmas,
  OOC:Error, OOC:AST, Sym := OOC:SymbolTable, Rep := OOC:Repository,
  XML := OOC:SymbolTable:XML, OOC:Auxiliary:ParseModule, OOC:Make;
  
CONST
  modeNameOnlyXML = 0;
  modeResolveNamesXML = 1;
  modeInterfaceXML = 2;
  
TYPE
  Rules = POINTER TO RulesDesc;
  RulesDesc = RECORD
    (Make.RulesDesc)
    resolve: BOOLEAN;
  END;
  
VAR
  cfgErrList: Error.List;
  i: LONGINT;
  arg: STRING;
  chars: Object.CharsLatin1;
  m: Rep.Module;

  mode: Options.Option;
  oo2cStyleErrors: Options.Option;
  makeRules: Rules;
  ok: BOOLEAN;

PROCEDURE InitRules (r: Rules);
  BEGIN
    Make.InitRules(r);
    r.resolve := mode.value(CfgData.IntegerVar).integer = modeResolveNamesXML;
    r.SetErrOut(StdChannels.stderr);
  END InitRules;

PROCEDURE NewRules(): Rules;
  VAR
    r: Rules;
  BEGIN
    NEW(r);
    InitRules(r);
    RETURN r;
  END NewRules;

PROCEDURE (r: Rules) CompileModule*(module: Rep.Module;
                                    analysisOnly: BOOLEAN): BOOLEAN
RAISES IO.Error;
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    pragmaHistory: Pragmas.History;
  BEGIN
    ParseModule.ParseModule (module, FALSE, TRUE, TRUE, FALSE, NIL, NIL,
                             ast, symTab, pragmaHistory, errList);
    (* symbol file is written by the `ParseModule' function *)
    r.WriteErrList(errList);
    RETURN (errList. msgCount = 0)
  END CompileModule;

PROCEDURE (r: Rules) UpdateSymbolTableXML*(m: Rep.Module): BOOLEAN
RAISES IO.Error;
(**Writes the description of the module's public interface as an XML document.
   *)
  VAR
    ast: AST.Node;
    symTab: Sym.Module;
    errList: Error.List;
    outputChannel: IO.ByteChannel;
    outputURI: URI.HierarchicalURI;
    pragmaHistory: Pragmas.History;
  BEGIN
    IF r.Update(m, Rep.modSymbolFile) THEN
      ParseModule.ParseModule (m, FALSE, r.resolve, FALSE, FALSE, NIL, NIL,
                               ast, symTab, pragmaHistory, errList);
      IF (errList. msgCount = 0) THEN
        outputURI := m. GetURI (Rep.modSymbolTableXML, FALSE);
        outputChannel := m. GetOutputChannel (Rep.modSymbolTableXML, FALSE);
        XML.Write (outputChannel, symTab);
        outputChannel. Close;
      END;
      IF (errList.msgCount # 0) THEN
        errList.Write(StdChannels.stderr);      
      END;
      RETURN (errList.msgCount = 0)
    ELSE
      RETURN FALSE;
    END;
  END UpdateSymbolTableXML;


PROCEDURE NewConfig;
  BEGIN
    mode := Config.AddOption ("mode", CfgData.NewIntegerVar(modeResolveNamesXML));
    oo2cStyleErrors := Config.AddOption ("oo2cStyleErrors", CfgData.NewBooleanVar(FALSE));
    
    Config.AddCmdLine ("--repository,-r",
                 "<repositories><file-system>$1</file-system></repositories>");
    Config.AddCmdLine ("--names-only-xml",
           "<options><set name='mode'>0</set></options>");
    Config.AddCmdLine ("--resolve-names-xml",
           "<options><set name='mode'>1</set></options>");
    Config.AddCmdLine ("--interface-xml",
           "<options><set name='mode'>2</set></options>");
    Config.AddCmdLine ("--terse-errors",
           "<options><set name='oo2cStyleErrors'>TRUE</set></options>");
  END NewConfig;

BEGIN
  cfgErrList := Error.NewList ("");
  NewConfig;
  Config.Read (cfgErrList);
  (* discard errors in config file 
  IF (cfgErrList. msgCount # 0) THEN
    cfgErrList. Write (StdChannels.stderr);
    HALT (1)
  END;*)

  IF (Config.arguments. ArgNumber() = 0) THEN
    Out.String ("Usage: TestSymTab [--names-only-xml|--resolve-names-xml|--interface-xml] [--terse-errors] -r <repository> <file>"); Out.Ln;
    HALT (1)
  ELSE
    IF oo2cStyleErrors.value(CfgData.BooleanVar). boolean THEN
      Error.style := Error.styleCharPos;
    END;
    
    makeRules := NewRules();
    ok := TRUE;
    FOR i := 0 TO Config.arguments. ArgNumber()-1 DO
      arg := Config.arguments.Get(i);
      arg := arg.ToString8("?");
      chars := arg(Object.String8).CharsLatin1();
      IF Rep.ValidModuleName(chars^) THEN
        m := Config.repositories.GetModule(chars^);
        IF (m = NIL) THEN
          Err.String ("Error: Cannot locate module ");
          Err.Object (arg);
          Err.Ln;
          HALT (1)
        ELSE
          CASE mode. value(CfgData.IntegerVar). integer OF
          | modeNameOnlyXML, modeResolveNamesXML:
            ok := makeRules.Update(m, Rep.modSymbolTableXML) & ok;
          | modeInterfaceXML:
            ok := makeRules.Update(m, Rep.modInterfaceXML) & ok;
          END;
        END
      ELSE
        Err.String ("Error: Invalid module name ");
        Err.Object (arg);
        Err.Ln;
        HALT (1)
      END
    END;
    IF ~ok THEN
      HALT (1)
    END
  END
END TestSymTab.
