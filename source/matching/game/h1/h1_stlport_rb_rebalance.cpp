/* STLport _Rb_global<bool>::_Rebalance (session b169b320): recolors and
 * rotates after an insertion so the red-black invariants hold. Uses the
 * already recovered rotations (0x80351f50 left, 0x80351fb0 right). Node
 * colors are bool (red = false), four bytes with this compiler. */

struct W3dRbNode
{
    bool color;
    W3dRbNode *parent;
    W3dRbNode *left;
    W3dRbNode *right;
};
extern "C" void w3d_auto_80351f50(W3dRbNode *x, W3dRbNode *&root);
extern "C" void w3d_auto_80351fb0(W3dRbNode *x, W3dRbNode *&root);
#define W3D_RED false
#define W3D_BLACK true
extern "C" void w3d_rb_rebalance_80352404(W3dRbNode *x, W3dRbNode *&root)
{
    x->color = W3D_RED;
    while (x != root && x->parent->color == W3D_RED) {
        if (x->parent == x->parent->parent->left) {
            W3dRbNode *y = x->parent->parent->right;
            if (y && y->color == W3D_RED) {
                x->parent->color = W3D_BLACK;
                y->color = W3D_BLACK;
                x->parent->parent->color = W3D_RED;
                x = x->parent->parent;
            }
            else {
                if (x == x->parent->right) {
                    x = x->parent;
                    w3d_auto_80351f50(x, root);
                }
                x->parent->color = W3D_BLACK;
                x->parent->parent->color = W3D_RED;
                w3d_auto_80351fb0(x->parent->parent, root);
            }
        }
        else {
            W3dRbNode *y = x->parent->parent->left;
            if (y && y->color == W3D_RED) {
                x->parent->color = W3D_BLACK;
                y->color = W3D_BLACK;
                x->parent->parent->color = W3D_RED;
                x = x->parent->parent;
            }
            else {
                if (x == x->parent->left) {
                    x = x->parent;
                    w3d_auto_80351fb0(x, root);
                }
                x->parent->color = W3D_BLACK;
                x->parent->parent->color = W3D_RED;
                w3d_auto_80351f50(x->parent->parent, root);
            }
        }
    }
    root->color = W3D_BLACK;
}

