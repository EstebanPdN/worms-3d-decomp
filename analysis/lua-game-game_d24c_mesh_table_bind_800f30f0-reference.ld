/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_mesh_table_bind_800f30f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
key_8040e078 = 0x8040e078;
load_8015adf4 = 0x8015adf4;
memcpy = 0x802eee50;
memmove = 0x802eeef4;
owner_80182150 = 0x80182150;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.d24c_mesh_table_bind_800f30f0 0x800f30f0 : { *(.text.d24c_mesh_table_bind_800f30f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
