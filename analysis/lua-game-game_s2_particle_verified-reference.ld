/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_particle_create_80106afc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800de930 = 0x800de930;
w3d_auto_800de958 = 0x800de958;
w3d_fn_800e06fc = 0x800e06fc;
w3d_fn_80106bd0 = 0x80106bd0;
w3d_obj_80361110 = 0x80361110;
w3d_obj_8040db38 = 0x8040db38;
w3d_obj_8040ffb8 = 0x8040ffb8;
w3d_obj_804106d0 = 0x804106d0;
w3d_obj_8044bec0 = 0x8044bec0;
w3d_obj_8044becc = 0x8044becc;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_particle_create_80106afc 0x80106afc : { *(.text.w3d_particle_create_80106afc) }
  .text.w3d_particle_destroy_80106c88 0x80106c88 : { *(.text.w3d_particle_destroy_80106c88) }
  .text.w3d_particle_wrap_80107ab8 0x80107ab8 : { *(.text.w3d_particle_wrap_80107ab8) }
  .text.w3d_particle_vector_message_80108154 0x80108154 : { *(.text.w3d_particle_vector_message_80108154) }
  .rodata 0x80399b00 : { *(.rodata) }
  .sdata 0x804b1850 (NOLOAD) : {
    . = 0x0; w3d_obj_804b1850 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
