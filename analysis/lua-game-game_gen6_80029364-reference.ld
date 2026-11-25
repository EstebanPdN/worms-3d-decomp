/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_body_80029364)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_data_803e7810 = 0x803e7810;
w3d_data_803e7880 = 0x803e7880;
w3d_data_803e78b8 = 0x803e78b8;
w3d_data_803e7998 = 0x803e7998;
w3d_fn_8002d778 = 0x8002d778;
w3d_fn_80160038 = 0x80160038;
w3d_fn_801629f8 = 0x801629f8;
w3d_global_8035fca0 = 0x8035fca0;
w3d_global_8035fd60 = 0x8035fd60;
w3d_global_8035fdc0 = 0x8035fdc0;
w3d_global_8035ff40 = 0x8035ff40;
w3d_global_803617d0 = 0x803617d0;
w3d_global_803618f0 = 0x803618f0;
w3d_registry_create_80029184 = 0x80029184;
w3d_registry_create_8002b280 = 0x8002b280;
w3d_registry_create_8003a3bc = 0x8003a3bc;
SECTIONS {
  .text.w3d_sinit_body_80029364 0x80029364 : { *(.text.w3d_sinit_body_80029364) }
  .text.w3d_sinit_body_8002b678 0x8002b678 : { *(.text.w3d_sinit_body_8002b678) }
  .text.w3d_sinit_body_8002dbb8 0x8002dbb8 : { *(.text.w3d_sinit_body_8002dbb8) }
  .text.w3d_sinit_body_8003a774 0x8003a774 : { *(.text.w3d_sinit_body_8003a774) }
  .text.w3d_member_8003af58 0x8003af58 : { *(.text.w3d_member_8003af58) }
  .text.w3d_member_8003af60 0x8003af60 : { *(.text.w3d_member_8003af60) }
  .text.w3d_copy12_8003e23c 0x8003e23c : { *(.text.w3d_copy12_8003e23c) }
  .text.w3d_member_8003e304 0x8003e304 : { *(.text.w3d_member_8003e304) }
  .text.w3d_getf_8003e30c 0x8003e30c : { *(.text.w3d_getf_8003e30c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
