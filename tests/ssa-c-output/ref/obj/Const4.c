#include <Const4.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Const4__P(OOC_CHAR8 b) {

l1_loop:
  
  goto l1_loop;
l3:
  ;
}

void Const4__Test(void) {

  Const4__P(1u);
  Out0__Ln();
  return;
  ;
}

void OOC_Const4_init(void) {

  return;
  ;
}

void OOC_Const4_destroy(void) {
}

/* --- */
