/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_counted_8019b424)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a66c0 = 0x801a66c0;
fn_801a6724 = 0x801a6724;
fn_801a688c = 0x801a688c;
fn_801a6908 = 0x801a6908;
fn_801ea0ec = 0x801ea0ec;
lbl_80413558 = 0x80413558;
SECTIONS {
  .text.w3d_s20_construct_counted_8019b424 0x8019b424 : { *(.text.w3d_s20_construct_counted_8019b424) }
  .text.w3d_s20_find_or_create_801a692c 0x801a692c : { *(.text.w3d_s20_find_or_create_801a692c) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
