/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_sphere_sweep_8014d1cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
hitPoint_80452310 = 0x80452310;
id_80178d1c = 0x80178d1c;
init_80131984 = 0x80131984;
post_8016239c = 0x8016239c;
same_80342a78 = 0x80342a78;
sqrt_802e82c0 = 0x802e82c0;
start_804522ec = 0x804522ec;
update_80178d28 = 0x80178d28;
SECTIONS {
  .text.d27d_worm_sphere_sweep_8014d1cc 0x8014d1cc : { *(.text.d27d_worm_sphere_sweep_8014d1cc) }
  .rodata 0x803a1618 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; shared_804ab400 = .;
    . = 0x6354; heap_804b1754 = .;
    . = 0x6470; best_804b1870 = .;
    . = 0x6474; limit_804b1874 = .;
    . = 0x6478; radius_804b1878 = .;
    . = 0x647c; hitOwner_804b187c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
