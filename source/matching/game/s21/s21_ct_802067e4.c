// desc: Appears to destroy every string held in the embedded vector at offset 48, empty the vector, clear the task list at offset 36 and return zero.
struct S21Text
{
  char *data;
};
struct S21Vector
{
  struct S21Text *begin;
  struct S21Text *end;
};
struct S21Object
{
  char pad[36];
  char tasks[12];
  struct S21Vector texts;
};
extern void fn_8020c5c4(struct S21Text *);
extern void fn_80341588(struct S21Text *);
extern void fn_80210afc(void *);
int w3d_s21_clear_texts_802067e4(struct S21Object *self)
{
  struct S21Text *begin = self->texts.begin;
  struct S21Vector *new_var;
  struct S21Vector *texts = &self->texts;
  struct S21Text *end = texts->end;
  void *tasks = self->tasks;
  struct S21Text *item = begin;
 do { new_var = texts; for (; item != end; item++) { fn_8020c5c4(item); fn_80341588(item); } new_var->end = begin; } while (0);
  fn_80210afc(tasks);
  return 0;
}
