#ifndef _EXPR_AST_H
#define _EXPR_AST_H

#include <vector>
#include <llvm/IR/Value.h>

using namespace llvm;

class ExpressionAST {
    public:
        virtual ~ExpressionAST();
        virtual Value* codegen() = 0;
};

// a + b, a * b, a + b * c, a + (b * c) -> Arithmetic binary (group in same as binary)
// a && b, a || b, a == b, a != b -> binary
// a = b
// &a, *a, -a, !a -> unary
// --a, ++a -> pre
// a++, a-- -> post
// a ? b : c -> ternary

#endif