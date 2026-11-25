/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_buffer_state_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_original_8017ea68 = 0x8017ea68;
w3d_original_801902e8 = 0x801902e8;
w3d_original_80190384 = 0x80190384;
w3d_original_8019800c = 0x8019800c;
w3d_original_801fe1f8 = 0x801fe1f8;
w3d_original_8020b680 = 0x8020b680;
w3d_original_8020f35c = 0x8020f35c;
w3d_original_8020f660 = 0x8020f660;
w3d_original_80210370 = 0x80210370;
w3d_original_80343944 = 0x80343944;
w3d_original_8034cc0c = 0x8034cc0c;
w3d_ref_buffer_state_vtable = 0x80412980;
w3d_ref_construction_callback_data = 0x803646e4;
w3d_ref_construction_config_data = 0x80364a04;
w3d_ref_construction_config_name = 0x803a7738;
w3d_ref_construction_desc0 = 0x80413db0;
w3d_ref_construction_desc1 = 0x804166b0;
w3d_ref_construction_desc2 = 0x80414210;
w3d_ref_construction_desc3 = 0x804135d0;
w3d_ref_construction_desc4 = 0x80413670;
w3d_ref_construction_desc5 = 0x80414260;
w3d_ref_construction_desc7 = 0x80417000;
w3d_ref_construction_desc8 = 0x80414030;
w3d_ref_construction_desc9 = 0x80413a68;
SECTIONS {
  .text.w3d_buffer_state_construct 0x8017ec0c : { *(.text.w3d_buffer_state_construct) }
  .text.w3d_buffer_state_destroy 0x8017f198 : { *(.text.w3d_buffer_state_destroy) }
  .text.w3d_buffer_state_reset 0x8017f638 : { *(.text.w3d_buffer_state_reset) }
  .text.w3d_buffer_construct 0x80197c8c : { *(.text.w3d_buffer_construct) }
  .text.w3d_buffer_destroy 0x80197ce4 : { *(.text.w3d_buffer_destroy) }
  .sdata 0x804ab614 (NOLOAD) : {
    . = 0x0; w3d_ref_buffer_state_instances = .;
    . = 0xe0; w3d_ref_buffer_mode = .;
    . = 0x4b70; w3d_ref_construction_shared0 = .;
    . = 0x4b70; w3d_ref_construction_shared0_set40 = .;
    . = 0x4b70; w3d_ref_construction_shared0_set50 = .;
    . = 0x4b74; w3d_ref_construction_shared1 = .;
    . = 0x4b78; w3d_ref_construction_shared2 = .;
    . = 0x4b7c; w3d_ref_construction_shared3 = .;
    . = 0x4b80; w3d_ref_construction_shared4 = .;
    . = 0x4b84; w3d_ref_construction_shared5 = .;
    . = 0x4b88; w3d_ref_construction_shared6 = .;
    . = 0x4b8c; w3d_ref_construction_shared7 = .;
    . = 0x4b90; w3d_ref_construction_shared8 = .;
    . = 0x4b94; w3d_ref_construction_shared9 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
