extern void fn_8016c7d0(void *,void *,int);
int s9_adjust_enable_8016d428(int self,int value)
{
    fn_8016c7d0(self ? (void *)(self-4):0,value,1);
    return 0;
}
