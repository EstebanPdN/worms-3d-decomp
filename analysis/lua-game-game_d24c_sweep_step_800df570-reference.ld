/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_sweep_step_800df570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_80389cb0 = 0x80389cb0;
as_80342a74 = 0x80342a74;
b_80389cb4 = 0x80389cb4;
identity_80341584 = 0x80341584;
result_8043ae20 = 0x8043ae20;
settings_801797b4 = 0x801797b4;
trace_800b0824 = 0x800b0824;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d24c_sweep_step_800df570 0x800df570 : { *(.text.d24c_sweep_step_800df570) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; ticks_804b1764 = .;
    . = 0x44; w_804b17a8 = .;
    . = 0x48; w_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
