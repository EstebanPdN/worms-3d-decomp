/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15b_gx_texgen_inverse_bind_8016c07c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_803a56d0 = 0x803a56d0;
inverse_80302da0 = 0x80302da0;
load_8030c0c8 = 0x8030c0c8;
object_803a56b0 = 0x803a56b0;
texgen_80307e24 = 0x80307e24;
SECTIONS {
  .text.w3d_cx15b_gx_texgen_inverse_bind_8016c07c 0x8016c07c : { *(.text.w3d_cx15b_gx_texgen_inverse_bind_8016c07c) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
