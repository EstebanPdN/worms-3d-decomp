/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41d_worm_downward_contact_search_80146b84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
end_80126524 = 0x80126524;
next_801264fc = 0x801264fc;
sqrt_802e82c0 = 0x802e82c0;
start_801263bc = 0x801263bc;
target_8003f240 = 0x8003f240;
SECTIONS {
  .text.w3d_d41d_worm_downward_contact_search_80146b84 0x80146b84 : { *(.text.w3d_d41d_worm_downward_contact_search_80146b84) }
  .rodata 0x803a0fd4 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; id_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
