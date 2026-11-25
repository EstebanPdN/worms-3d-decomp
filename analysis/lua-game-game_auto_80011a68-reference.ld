/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80011a68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8001523C = 0x8001523c;
fn_80015264 = 0x80015264;
fn_800FC6DC = 0x800fc6dc;
fn_800FC7F8 = 0x800fc7f8;
fn_802098B4 = 0x802098b4;
fn_802098D8 = 0x802098d8;
fn_80209920 = 0x80209920;
fn_8020B208 = 0x8020b208;
SECTIONS {
  .text.w3d_auto_80011a68 0x80011a68 : { *(.text.w3d_auto_80011a68) }
  .text.w3d_auto_80011c50 0x80011c50 : { *(.text.w3d_auto_80011c50) }
  .text.w3d_auto_80011f28 0x80011f28 : { *(.text.w3d_auto_80011f28) }
  .text.w3d_auto_80012010 0x80012010 : { *(.text.w3d_auto_80012010) }
  .text.w3d_auto_80012104 0x80012104 : { *(.text.w3d_auto_80012104) }
  .text.w3d_auto_800122b4 0x800122b4 : { *(.text.w3d_auto_800122b4) }
  .text.w3d_auto_80015228 0x80015228 : { *(.text.w3d_auto_80015228) }
  .text.w3d_auto_8001523c 0x8001523c : { *(.text.w3d_auto_8001523c) }
  .text.w3d_auto_80015264 0x80015264 : { *(.text.w3d_auto_80015264) }
  .text.w3d_auto_8001528c 0x8001528c : { *(.text.w3d_auto_8001528c) }
  .text.w3d_auto_800152ac 0x800152ac : { *(.text.w3d_auto_800152ac) }
  .text.w3d_auto_800152cc 0x800152cc : { *(.text.w3d_auto_800152cc) }
  .text.w3d_auto_800153dc 0x800153dc : { *(.text.w3d_auto_800153dc) }
  .text.w3d_auto_80015488 0x80015488 : { *(.text.w3d_auto_80015488) }
  .text.w3d_auto_800154b4 0x800154b4 : { *(.text.w3d_auto_800154b4) }
  .sdata 0x804aa5b8 (NOLOAD) : {
    . = 0x0; lbl_804AA5B8 = .;
    . = 0xc4; lbl_804AA67C = .;
    . = 0xc8; lbl_804AA680 = .;
    . = 0xcc; lbl_804AA684 = .;
    . = 0xd0; lbl_804AA688 = .;
    . = 0xd4; lbl_804AA68C = .;
    . = 0xfc; lbl_804AA6B4 = .;
    . = 0x2298; lbl_804AC850 = .;
    . = 0x229c; lbl_804AC854 = .;
    . = 0x22a0; lbl_804AC858 = .;
    . = 0x22a4; lbl_804AC85C = .;
    . = 0x22a8; lbl_804AC860 = .;
    . = 0x22ac; lbl_804AC864 = .;
    . = 0x22b0; lbl_804AC868 = .;
    . = 0x22b4; lbl_804AC86C = .;
    . = 0x22b8; lbl_804AC870 = .;
    . = 0x22e0; lbl_804AC898 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
