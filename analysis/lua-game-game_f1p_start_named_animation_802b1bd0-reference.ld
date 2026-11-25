/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_start_named_animation_802b1bd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
error_803d7a98 = 0x803d7a98;
fn_80181598 = 0x80181598;
fn_80181640 = 0x80181640;
fn_8020c510 = 0x8020c510;
fn_802b1cec = 0x802b1cec;
fn_80343584 = 0x80343584;
rate_803d7ab8 = 0x803d7ab8;
zero_803d7abc = 0x803d7abc;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_start_named_animation_802b1bd0 0x802b1bd0 : { *(.text.w3d_start_named_animation_802b1bd0) }
  .sdata 0x804abb44 (NOLOAD) : {
    . = 0x0; instance_804abb44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
