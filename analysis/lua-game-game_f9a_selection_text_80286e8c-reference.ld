/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f9a_selection_text_80286e8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
empty_803cf460 = 0x803cf460;
error_803cf4c4 = 0x803cf4c4;
fn_800fc1b0 = 0x800fc1b0;
fn_801790bc = 0x801790bc;
fn_80179170 = 0x80179170;
fn_8020bb2c = 0x8020bb2c;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b1714 = 0x802b1714;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343744 = 0x80343744;
SECTIONS {
  .text.w3d_f9a_selection_text_80286e8c 0x80286e8c : { *(.text.w3d_f9a_selection_text_80286e8c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
