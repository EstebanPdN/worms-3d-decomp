/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_screen_show_800c7cd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
fn_80173df0 = 0x80173df0;
fn_801fdfb8 = 0x801fdfb8;
fn_801fe45c = 0x801fe45c;
fn_8034357c = 0x8034357c;
fn_80343994 = 0x80343994;
lbl_80387a7c = 0x80387a7c;
lbl_80387a8c = 0x80387a8c;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25h_screen_show_800c7cd0 0x800c7cd0 : { *(.text.w3d_d25h_screen_show_800c7cd0) }
  .rodata 0x80387a9c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . = 0x64; lbl_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
