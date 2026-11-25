// Original vertical rejection uses > followed by !<. Replacing it with
// inclusive range checks changes unordered behavior: NaN y proceeds to spans.
// Horizontal inclusive tests retain their original ordered comparisons.
// Labels preserve original shared return paths; empty spans yield index -1.
// Partial views do not establish original declarations or complete sizeof.
// Partial hit-region view: offsets and widths observed, semantic names inferred.
struct cc37b_LineSpan {unsigned unknown00;float left,right;unsigned unknown0c[3];};
struct cc37b_SpanRange {cc37b_LineSpan *begin,*end; inline cc37b_LineSpan* start() const {return begin;} inline cc37b_LineSpan* finish() const {return end;}};
struct cc37b_TextRegion {
 unsigned char unknown00[0x14];int enabled;
 unsigned char unknown18[0xc];float halfHeight,originX,originY;
 unsigned char unknown30[0x20];cc37b_SpanRange spans;
};
extern "C" int w3d_cc37b_hit_line_802bfa70(float x,float y,cc37b_TextRegion* region,int* index) {
 if(region->enabled) goto enabled;
 rejected: return 0;
 enabled:
 {
  cc37b_LineSpan* span=region->spans.start();
  *index=0;
  if(region->originY-region->halfHeight>y) goto rejected;
  if(!(region->originY+region->halfHeight<y)) goto scan;
  goto rejected;
 accepted: return 1;
 scan:
  {
   if(span!=region->spans.finish()) do {
    if(span->left+region->originX<=x && span->right+region->originX>=x) goto accepted;
    ++span; ++*index;
   } while(span!=region->spans.finish());
   --*index;
   return 1;
  }
 }
 return 0;
}
