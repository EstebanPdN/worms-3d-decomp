/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_accumulate_offset_800e9528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003888c = 0x8003888c;
fn_800f6afc = 0x800f6afc;
fn_8015aee8 = 0x8015aee8;
fn_8015af24 = 0x8015af24;
fn_80164fc8 = 0x80164fc8;
fn_8021eb00 = 0x8021eb00;
fn_8026c96c = 0x8026c96c;
fn_8026cc60 = 0x8026cc60;
lbl_8038b27c = 0x8038b27c;
SECTIONS {
  .text.w3d_s20_accumulate_offset_800e9528 0x800e9528 : { *(.text.w3d_s20_accumulate_offset_800e9528) }
  .text.w3d_s20_swap_handles_800f3028 0x800f3028 : { *(.text.w3d_s20_swap_handles_800f3028) }
  .text.w3d_s20_replace_held_800f3524 0x800f3524 : { *(.text.w3d_s20_replace_held_800f3524) }
  .text.w3d_s20_can_accept_id_800f899c 0x800f899c : { *(.text.w3d_s20_can_accept_id_800f899c) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804aaabc = .;
    . = 0x1004; lbl_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
