/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol29a_texture_set_construct_800f2ad0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__22Sol29aService_801628b0 = 0x801628b0;
_vt.16Sol29aTextureSet = 0x804103e8;
fn_8026c714 = 0x8026c714;
fn_803426b8 = 0x803426b8;
SECTIONS {
  .text.sol29a_texture_set_construct_800f2ad0 0x800f2ad0 : { *(.text.sol29a_texture_set_construct_800f2ad0) }
  .sdata 0x804b184c (NOLOAD) : {
    . = 0x0; instance_804b184c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
