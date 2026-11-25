/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41j_gx_driver_ctor_80169c10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bind_source_801a31ec = 0x801a31ec;
construct_801f2678 = 0x801f2678;
identity_8045e748 = 0x8045e748;
new_buffers_801a25a0 = 0x801a25a0;
setting_read_80206920 = 0x80206920;
tag_init_801e81c8 = 0x801e81c8;
vt_80411d00 = 0x80411d00;
vt_80411d70 = 0x80411d70;
vt_80411de0 = 0x80411de0;
SECTIONS {
  .text.w3d_d41j_gx_driver_ctor_80169c10 0x80169c10 : { *(.text.w3d_d41j_gx_driver_ctor_80169c10) }
  .rodata 0x803a50a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
