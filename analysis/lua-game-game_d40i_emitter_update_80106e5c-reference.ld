/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40i_emitter_update_80106e5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bounds_80107ccc = 0x80107ccc;
cfg_801797b4 = 0x801797b4;
colours_80189760 = 0x80189760;
hit_800dca14 = 0x800dca14;
inverse_801f6c2c = 0x801f6c2c;
lookup_80164fc8 = 0x80164fc8;
near_80107f54 = 0x80107f54;
orient_80107d70 = 0x80107d70;
points_80189518 = 0x80189518;
ref_80341584 = 0x80341584;
remove_8015fd1c = 0x8015fd1c;
second_80189828 = 0x80189828;
sqrt_802e82c0 = 0x802e82c0;
wrap_80107ab8 = 0x80107ab8;
zero_80399adc = 0x80399adc;
SECTIONS {
  .text.d40i_emitter_update_80106e5c 0x80106e5c : { *(.text.d40i_emitter_update_80106e5c) }
  .rodata 0x80399ae0 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; camera_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
