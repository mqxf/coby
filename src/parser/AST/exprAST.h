#ifndef _EXPR_AST_H
#define _EXPR_AST_H

#include <vector>

class ExpressionAST {
    public:
        virtual ~ExpressionAST();
};

// a + b, a * b, a + b * c, a + (b * c) -> Arithmetic
// a && b, a || b, a == b, a != b -> binary
// a = b
// &a, *a, -a, !a -> unary
// --a, ++a -> pre
// a++, a-- -> post
// a ? b : c -> ternary

#endif