/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_write_pipe_command_8016ac3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_cc008000 = 0xcc008000;
SECTIONS {
  .text.w3d_s20_write_pipe_command_8016ac3c 0x8016ac3c : { *(.text.w3d_s20_write_pipe_command_8016ac3c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
