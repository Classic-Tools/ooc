#include <OOC/Logger.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_Logger__WriteURI(URI__URI uri) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 str[1024];

  i0 = (OOC_INT32)uri;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 316)))), &_td_URI_Scheme_File__URIDesc);
  if (i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 372)))), URI__URIDesc_GetString)),URI__URIDesc_GetString)((URI__URI)i0, (void*)(OOC_INT32)str, 1024);
  goto l4;
l3:
  URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)i0, (void*)(OOC_INT32)str, 1024);
l4:
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l7;
  Out__String((void*)(OOC_INT32)str, 1024);
l7:
  return;
  ;
}

void OOC_Logger__ReadFile(URI__URI uri) {
  register OOC_INT32 i0;

  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l4;
  Out__String("- ", 3);
  i0 = (OOC_INT32)uri;
  OOC_Logger__WriteURI((URI__URI)i0);
  Out__Ln();
  Out__Flush();
l4:
  return;
  ;
}

void OOC_Logger__ReadFileName(const OOC_CHAR8 fileName__ref[], OOC_LEN fileName_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(fileName,OOC_CHAR8 ,fileName_0d)

  OOC_INITIALIZE_VPAR(fileName__ref,fileName,OOC_CHAR8 ,fileName_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l4;
  Out__String("- ", 3);
  Out__String((void*)(OOC_INT32)fileName, fileName_0d);
  Out__Ln();
  Out__Flush();
l4:
  return;
  ;
}

void OOC_Logger__WriteFile(URI__URI uri) {
  register OOC_INT32 i0;

  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l4;
  Out__String("+ ", 3);
  i0 = (OOC_INT32)uri;
  OOC_Logger__WriteURI((URI__URI)i0);
  Out__Ln();
  Out__Flush();
l4:
  return;
  ;
}

void OOC_Logger__WriteFileName(const OOC_CHAR8 fileName__ref[], OOC_LEN fileName_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(fileName,OOC_CHAR8 ,fileName_0d)

  OOC_INITIALIZE_VPAR(fileName__ref,fileName,OOC_CHAR8 ,fileName_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l4;
  Out__String("+ ", 3);
  Out__String((void*)(OOC_INT32)fileName, fileName_0d);
  Out__Ln();
  Out__Flush();
l4:
  return;
  ;
}

void OOC_Logger__ShellCommand(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (!i0) goto l4;
  Out__String((void*)(OOC_INT32)str, str_0d);
  Out__Ln();
  Out__Flush();
l4:
  return;
  ;
}

static void OOC_Logger__IndentMake(void) {
  register OOC_INT32 i0,i1,i2;

  Out__String("[make]", 7);
  i0 = OOC_Logger__indentMake;
  i1 = 1<=i0;
  if (!i1) goto l8;
  i1=1;
l3_loop:
  Out__String("  ", 3);
  i1 = i1+1;
  i2 = i1<=i0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void OOC_Logger__EnterMake(const OOC_CHAR8 rule__ref[], OOC_LEN rule_0d, const OOC_CHAR8 module__ref[], OOC_LEN module_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(rule,OOC_CHAR8 ,rule_0d)
  OOC_ALLOCATE_VPAR(module,OOC_CHAR8 ,module_0d)

  OOC_INITIALIZE_VPAR(rule__ref,rule,OOC_CHAR8 ,rule_0d)
  OOC_INITIALIZE_VPAR(module__ref,module,OOC_CHAR8 ,module_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0=0u;
l5:
  if (!i0) goto l7;
  OOC_Logger__IndentMake();
  Out__String("enter ", 7);
  Out__String((void*)(OOC_INT32)rule, rule_0d);
  Out__String(" for ", 6);
  Out__String((void*)(OOC_INT32)module, module_0d);
  Out__Ln();
  i0 = OOC_Logger__indentMake;
  OOC_Logger__indentMake = (i0+1);
l7:
  return;
  ;
}

OOC_CHAR8 OOC_Logger__ExitMake(const OOC_CHAR8 rule__ref[], OOC_LEN rule_0d, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, OOC_CHAR8 success) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(rule,OOC_CHAR8 ,rule_0d)
  OOC_ALLOCATE_VPAR(module,OOC_CHAR8 ,module_0d)

  OOC_INITIALIZE_VPAR(rule__ref,rule,OOC_CHAR8 ,rule_0d)
  OOC_INITIALIZE_VPAR(module__ref,module,OOC_CHAR8 ,module_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l4;
l3:
  i0=0u;
l4:
  i1 = success;
  if (!i0) goto l11;
  i0 = OOC_Logger__indentMake;
  OOC_Logger__indentMake = (i0-1);
  OOC_Logger__IndentMake();
  Out__String("leave ", 7);
  Out__String((void*)(OOC_INT32)rule, rule_0d);
  Out__String(" for ", 6);
  Out__String((void*)(OOC_INT32)module, module_0d);
  if (i1) goto l9;
  Out__String(" (failure)", 11);
  goto l10;
l9:
  Out__String(" (success)", 11);
l10:
  Out__Ln();
l11:
  return i1;
  ;
}

OOC_CHAR8 OOC_Logger__CachedMake(const OOC_CHAR8 rule__ref[], OOC_LEN rule_0d, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, OOC_CHAR8 success) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(rule,OOC_CHAR8 ,rule_0d)
  OOC_ALLOCATE_VPAR(module,OOC_CHAR8 ,module_0d)

  OOC_INITIALIZE_VPAR(rule__ref,rule,OOC_CHAR8 ,rule_0d)
  OOC_INITIALIZE_VPAR(module__ref,module,OOC_CHAR8 ,module_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l4;
l3:
  i0=0u;
l4:
  i1 = success;
  if (!i0) goto l11;
  OOC_Logger__IndentMake();
  Out__String("cached result: ", 16);
  Out__String((void*)(OOC_INT32)rule, rule_0d);
  Out__String(" for ", 6);
  Out__String((void*)(OOC_INT32)module, module_0d);
  if (i1) goto l9;
  Out__String(" (failure)", 11);
  goto l10;
l9:
  Out__String(" (success)", 11);
l10:
  Out__Ln();
l11:
  return i1;
  ;
}

void OOC_Logger__ExplainMake(const OOC_CHAR8 s1__ref[], OOC_LEN s1_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(s1,OOC_CHAR8 ,s1_0d)

  OOC_INITIALIZE_VPAR(s1__ref,s1,OOC_CHAR8 ,s1_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0=0u;
l5:
  if (!i0) goto l7;
  OOC_Logger__IndentMake();
  Out__String((void*)(OOC_INT32)s1, s1_0d);
  Out__Ln();
l7:
  return;
  ;
}

void OOC_Logger__ExplainFileMake(const OOC_CHAR8 s1__ref[], OOC_LEN s1_0d, URI__URI uri1, const OOC_CHAR8 s2__ref[], OOC_LEN s2_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(s1,OOC_CHAR8 ,s1_0d)
  OOC_ALLOCATE_VPAR(s2,OOC_CHAR8 ,s2_0d)

  OOC_INITIALIZE_VPAR(s1__ref,s1,OOC_CHAR8 ,s1_0d)
  OOC_INITIALIZE_VPAR(s2__ref,s2,OOC_CHAR8 ,s2_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0=0u;
l5:
  if (!i0) goto l7;
  OOC_Logger__IndentMake();
  Out__String((void*)(OOC_INT32)s1, s1_0d);
  i0 = (OOC_INT32)uri1;
  OOC_Logger__WriteURI((URI__URI)i0);
  Out__String((void*)(OOC_INT32)s2, s2_0d);
  Out__Ln();
l7:
  return;
  ;
}

void OOC_Logger__ExplainFilesMake(const OOC_CHAR8 s1__ref[], OOC_LEN s1_0d, URI__URI uri1, const OOC_CHAR8 s2__ref[], OOC_LEN s2_0d, URI__URI uri2, const OOC_CHAR8 s3__ref[], OOC_LEN s3_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(s1,OOC_CHAR8 ,s1_0d)
  OOC_ALLOCATE_VPAR(s2,OOC_CHAR8 ,s2_0d)
  OOC_ALLOCATE_VPAR(s3,OOC_CHAR8 ,s3_0d)

  OOC_INITIALIZE_VPAR(s1__ref,s1,OOC_CHAR8 ,s1_0d)
  OOC_INITIALIZE_VPAR(s2__ref,s2,OOC_CHAR8 ,s2_0d)
  OOC_INITIALIZE_VPAR(s3__ref,s3,OOC_CHAR8 ,s3_0d)
  i0 = OOC_Logger__silence;
  i0 = !i0;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0=0u;
l5:
  if (!i0) goto l7;
  OOC_Logger__IndentMake();
  Out__String((void*)(OOC_INT32)s1, s1_0d);
  i0 = (OOC_INT32)uri1;
  OOC_Logger__WriteURI((URI__URI)i0);
  Out__String((void*)(OOC_INT32)s2, s2_0d);
  i0 = (OOC_INT32)uri2;
  OOC_Logger__WriteURI((URI__URI)i0);
  Out__String((void*)(OOC_INT32)s3, s3_0d);
  Out__Ln();
l7:
  return;
  ;
}

void OOC_OOC_Logger_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Scheme_File__GetCwd();
  OOC_Logger__cwd = (URI_Scheme_File__URI)i0;
  OOC_Logger__indentMake = 0;
  OOC_Logger__silence = 0u;
  return;
  ;
}

/* --- */
