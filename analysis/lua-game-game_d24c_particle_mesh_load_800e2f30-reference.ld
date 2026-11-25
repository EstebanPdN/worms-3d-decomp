/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_particle_mesh_load_800e2f30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
array_delete_801fe240 = 0x801fe240;
array_new_801fe220 = 0x801fe220;
as_mesh_8034380c = 0x8034380c;
as_text_80343584 = 0x80343584;
identity_80341584 = 0x80341584;
load_8015adf4 = 0x8015adf4;
lookup_80164fc8 = 0x80164fc8;
mesh_alloc_8018920c = 0x8018920c;
mesh_flags_80189704 = 0x80189704;
mesh_names_80389fd4 = 0x80389fd4;
random_8015ff5c = 0x8015ff5c;
read_800fc1b0 = 0x800fc1b0;
service_8015ae3c = 0x8015ae3c;
settings_801797b4 = 0x801797b4;
SECTIONS {
  .text.d24c_particle_mesh_load_800e2f30 0x800e2f30 : { *(.text.d24c_particle_mesh_load_800e2f30) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
