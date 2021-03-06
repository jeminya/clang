// RUN: clang-diff -ast-dump %s -- -std=c++11 | FileCheck %s


// CHECK: {{^}}TranslationUnitDecl(0)
// CHECK: {{^}} NamespaceDecl: test;(
namespace test {

// CHECK: {{^}} FunctionDecl: test::f(
// CHECK: CompoundStmt(
void f() {
  // CHECK: VarDecl: i(int)(
  // CHECK: IntegerLiteral: 1
  auto i = 1;
  // CHECK: FloatingLiteral: 1.5(
  auto r = 1.5;
  // CHECK: CXXBoolLiteralExpr: true(
  auto b = true;
  // CHECK: CallExpr(
  // CHECK-NOT: ImplicitCastExpr
  // CHECK: DeclRefExpr: test::f(
  f();
  // CHECK: UnaryOperator: ++(
  ++i;
  // CHECK: BinaryOperator: =(
  i = i;
}

} // end namespace test

// CHECK: UsingDirectiveDecl: test(
using namespace test;

// CHECK: TypedefDecl: nat;unsigned int;(
typedef unsigned nat;
// CHECK: TypeAliasDecl: real;double;(
using real = double;

class Base {
};

// CHECK: CXXRecordDecl: X;X;(
class X : Base {
  int m;
  // CHECK: CXXMethodDecl: X::foo(const char *(int)
  // CHECK: ParmVarDecl: i(int)(
  const char *foo(int i) {
    if (i == 0)
      // CHECK: StringLiteral: foo(
      return "foo";
    // CHECK-NOT: ImplicitCastExpr
    return 0;
  }

  // CHECK: AccessSpecDecl: public(
public:
  int not_initialized;
  // All initialized members, bases and delegating initializers are are
  // appended, separated by commas.
  // CHECK: CXXConstructorDecl: X::X(void (char, int){{( __attribute__\(\(thiscall\)\))?}})Base,X::m,(
  X(char c, int) : Base(), m(0) {
    // CHECK: MemberExpr: X::m(
    int x = m;
  }
  // CHECK: CXXConstructorDecl: X::X(void (char){{( __attribute__\(\(thiscall\)\))?}})X,(
  X(char s) : X(s, 4) {}
};

#define M (void)1
#define MA(a, b) (void)a, b
// CHECK: FunctionDecl
// CHECK-NEXT: CompoundStmt
void macros() {
  M;
  MA(1, 2);
}

#ifndef GUARD
#define GUARD
// CHECK-NEXT: NamespaceDecl
namespace world {
// nodes from other files are excluded, there should be no output here
#include "clang-diff-ast.cpp"
}
// CHECK-NEXT: FunctionDecl: sentinel
void sentinel();
#endif
