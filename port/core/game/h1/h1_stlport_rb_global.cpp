#include "w3d_ptr.h"
#line 1 "h1_stlport_rb_global.cpp"
/* STLport _Rb_global<bool>::_M_increment and _Rebalance_for_erase
 * (session b169b320), written as in STLport's _tree.c with the recovered
 * rotations (0x80351f50 left, 0x80351fb0 right). Colors are bool
 * (red = false). */

struct W3dRbNode
{
    bool color;
    Ptr32<W3dRbNode> parent;
    Ptr32<W3dRbNode> left;
    Ptr32<W3dRbNode> right;
};
extern "C" void w3d_auto_80351f50(Ptr32<W3dRbNode> x, Ptr32<W3dRbNode> &root);
extern "C" void w3d_auto_80351fb0(Ptr32<W3dRbNode> x, Ptr32<W3dRbNode> &root);
#define W3D_RED false
#define W3D_BLACK true
static inline Ptr32<W3dRbNode> w3d_rb_minimum(Ptr32<W3dRbNode> x) { while (x->left != 0) x = x->left; return x; }
static inline Ptr32<W3dRbNode> w3d_rb_maximum(Ptr32<W3dRbNode> x) { while (x->right != 0) x = x->right; return x; }
template <class T> inline void w3d_swap(T &a, T &b) { T tmp = a; a = b; b = tmp; }
extern "C" Ptr32<W3dRbNode> w3d_rb_increment_80351ef8(Ptr32<W3dRbNode> node)
{
    if (node->right != 0) {
        node = node->right;
        while (node->left != 0)
            node = node->left;
    }
    else {
        Ptr32<W3dRbNode> y = node->parent;
        while (node == y->right) {
            node = y;
            y = y->parent;
        }
        if (node->right != y)
            node = y;
    }
    return node;
}

extern "C" Ptr32<W3dRbNode> w3d_rb_rebalance_for_erase_80352010(Ptr32<W3dRbNode> z, Ptr32<W3dRbNode> &root,
                                                         Ptr32<W3dRbNode> &leftmost, Ptr32<W3dRbNode> &rightmost)
{
    Ptr32<W3dRbNode> y = z;
    Ptr32<W3dRbNode> x = 0;
    Ptr32<W3dRbNode> x_parent = 0;
    if (y->left == 0)
        x = y->right;
    else
        if (y->right == 0)
            x = y->left;
        else {
            y = y->right;
            while (y->left != 0)
                y = y->left;
            x = y->right;
        }
    if (y != z) {
        z->left->parent = y;
        y->left = z->left;
        if (y != z->right) {
            x_parent = y->parent;
            if (x) x->parent = y->parent;
            y->parent->left = x;
            y->right = z->right;
            z->right->parent = y;
        }
        else
            x_parent = y;
        if (root == z)
            root = y;
        else if (z->parent->left == z)
            z->parent->left = y;
        else
            z->parent->right = y;
        y->parent = z->parent;
        w3d_swap(y->color, z->color);
        y = z;
    }
    else {
        x_parent = y->parent;
        if (x) x->parent = y->parent;
        if (root == z)
            root = x;
        else
            if (z->parent->left == z)
                z->parent->left = x;
            else
                z->parent->right = x;
        if (leftmost == z)
            if (z->right == 0)
                leftmost = z->parent;
            else
                leftmost = w3d_rb_minimum(x);
        if (rightmost == z)
            if (z->left == 0)
                rightmost = z->parent;
            else
                rightmost = w3d_rb_maximum(x);
    }
    if (y->color != W3D_RED) {
        while (x != root && (x == 0 || x->color == W3D_BLACK))
            if (x == x_parent->left) {
                Ptr32<W3dRbNode> w = x_parent->right;
                if (w->color == W3D_RED) {
                    w->color = W3D_BLACK;
                    x_parent->color = W3D_RED;
                    w3d_auto_80351f50(x_parent, root);
                    w = x_parent->right;
                }
                if ((w->left == 0 || w->left->color == W3D_BLACK) &&
                    (w->right == 0 || w->right->color == W3D_BLACK)) {
                    w->color = W3D_RED;
                    x = x_parent;
                    x_parent = x_parent->parent;
                } else {
                    if (w->right == 0 || w->right->color == W3D_BLACK) {
                        if (w->left) w->left->color = W3D_BLACK;
                        w->color = W3D_RED;
                        w3d_auto_80351fb0(w, root);
                        w = x_parent->right;
                    }
                    w->color = x_parent->color;
                    x_parent->color = W3D_BLACK;
                    if (w->right) w->right->color = W3D_BLACK;
                    w3d_auto_80351f50(x_parent, root);
                    break;
                }
            } else {
                Ptr32<W3dRbNode> w = x_parent->left;
                if (w->color == W3D_RED) {
                    w->color = W3D_BLACK;
                    x_parent->color = W3D_RED;
                    w3d_auto_80351fb0(x_parent, root);
                    w = x_parent->left;
                }
                if ((w->right == 0 || w->right->color == W3D_BLACK) &&
                    (w->left == 0 || w->left->color == W3D_BLACK)) {
                    w->color = W3D_RED;
                    x = x_parent;
                    x_parent = x_parent->parent;
                } else {
                    if (w->left == 0 || w->left->color == W3D_BLACK) {
                        if (w->right) w->right->color = W3D_BLACK;
                        w->color = W3D_RED;
                        w3d_auto_80351f50(w, root);
                        w = x_parent->left;
                    }
                    w->color = x_parent->color;
                    x_parent->color = W3D_BLACK;
                    if (w->left) w->left->color = W3D_BLACK;
                    w3d_auto_80351fb0(x_parent, root);
                    break;
                }
            }
        if (x) x->color = W3D_BLACK;
    }
    return y;
}



