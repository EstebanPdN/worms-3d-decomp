/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_query_int_80176b2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177eb0 = 0x80177eb0;
fn_80178f54 = 0x80178f54;
fn_80179170 = 0x80179170;
fn_801799d4 = 0x801799d4;
fn_80343744 = 0x80343744;
fn_80343df4 = 0x80343df4;
lbl_80412e20 = 0x80412e20;
SECTIONS {
  .text.w3d_s20_query_int_80176b2c 0x80176b2c : { *(.text.w3d_s20_query_int_80176b2c) }
  .text.w3d_s20_query_int_80176c68 0x80176c68 : { *(.text.w3d_s20_query_int_80176c68) }
  .text.w3d_s20_replace_owned_801784e4 0x801784e4 : { *(.text.w3d_s20_replace_owned_801784e4) }
  .text.w3d_s20_destruct_counted_80188ab8 0x80188ab8 : { *(.text.w3d_s20_destruct_counted_80188ab8) }
  .sdata 0x804ab69c (NOLOAD) : {
    . = 0x0; lbl_804ab69c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
