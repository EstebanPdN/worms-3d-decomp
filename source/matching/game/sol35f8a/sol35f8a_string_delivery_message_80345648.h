#pragma interface
namespace sol35f8a_string_delivery_message_80345648 {
struct Base_80410500 { unsigned short key; unsigned time; virtual void *make_message(); };
struct Record_804104e0 : Base_80410500 { Sol35f8aPoolString text; virtual void *make_message(); };
typedef Record_804104e0 Record;
}
