/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_lunar_8026cf8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_803426b8 = 0x803426b8;
fn_8015fef0 = 0x8015fef0;
fn_8020bd38 = 0x8020bd38;
name_803cbcf0 = 0x803cbcf0;
one_803cbd00 = 0x803cbd00;
vt_8041bd20 = 0x8041bd20;
zero_803cbcfc = 0x803cbcfc;
SECTIONS {
  .text.w3d_construct_lunar_8026cf8c 0x8026cf8c : { *(.text.w3d_construct_lunar_8026cf8c) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; instance_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
