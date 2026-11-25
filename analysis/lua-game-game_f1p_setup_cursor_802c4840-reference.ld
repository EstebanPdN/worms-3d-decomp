/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_setup_cursor_802c4840)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15F1pResourceTextPCc = 0x8020bb54;
cursor_803d87c4 = 0x803d87c4;
fn_8015adf4 = 0x8015adf4;
fn_8020c5c4 = 0x8020c5c4;
fn_802c4998 = 0x802c4998;
fn_80341588 = 0x80341588;
fn_8034357c = 0x8034357c;
sx_803d87d8 = 0x803d87d8;
sy_803d87dc = 0x803d87dc;
sz_803d87e0 = 0x803d87e0;
SECTIONS {
  .text.w3d_setup_cursor_802c4840 0x802c4840 : { *(.text.w3d_setup_cursor_802c4840) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; depth_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
