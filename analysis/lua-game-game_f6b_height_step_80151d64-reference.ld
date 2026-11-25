/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f6b_height_step_80151d64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__19Trajectory_801181bc = 0x801181bc;
allocate_801613f0 = 0x801613f0;
construct_80131b50 = 0x80131b50;
destroy_80118200 = 0x80118200;
height_80118a5c = 0x80118a5c;
post_8016239c = 0x8016239c;
reset_8015286c = 0x8015286c;
set_a_80118288 = 0x80118288;
set_b_80118230 = 0x80118230;
set_c_80118268 = 0x80118268;
SECTIONS {
  .text.f6b_height_step_80151d64 0x80151d64 : { *(.text.f6b_height_step_80151d64) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
