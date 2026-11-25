#include "w3d_ptr.h"
#line 1 "f1p_build_card_record_802ab804.cpp"
// Observed fixed-size save record and card metadata fields; semantic names inferred.
struct F1pCardPayload{unsigned words[2048];};struct F1pCardRecord{unsigned checksum,bytes,version;char title[32],description[32];F1pCardPayload payload;};struct F1pCardMetadata{char name[32];unsigned timestamp;Ptr32<F1pCardRecord> record;char unknown40[6];unsigned char flags,unknown47;unsigned image;unsigned short format,unknown54;unsigned offset,count;unsigned short speed[4],unknown72;char unknown74[6];unsigned short unknown80;};
extern "C" Ptr32<char> fn_802efbfc(Ptr32<char>,Ptr32<const char>,unsigned);extern "C" void fn_802fa988(Ptr32<void>,unsigned);
extern "C" void w3d_build_card_record_802ab804(Ptr32<const char> name,Ptr32<const char> title,Ptr32<const char> description,unsigned timestamp,Ptr32<F1pCardRecord> output,unsigned version,Ptr32<const F1pCardPayload> payload,Ptr32<void> unused,Ptr32<F1pCardMetadata> metadata,Ptr32<F1pCardRecord> scratch){scratch->checksum=0;scratch->bytes=8268;scratch->version=version;fn_802efbfc(scratch->title,title,32);fn_802efbfc(scratch->description,description,32);scratch->payload=*payload;*output=*scratch;fn_802fa988(output,8268);fn_802efbfc(metadata->name,name,32);metadata->flags=0;metadata->timestamp=timestamp;metadata->record=output;metadata->offset=12;metadata->image=76;metadata->count=4;metadata->format=2;metadata->unknown80=0;metadata->speed[0]=2;metadata->speed[1]=2;metadata->speed[2]=2;metadata->speed[3]=2;metadata->unknown72=0;}


