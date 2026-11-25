/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_projectile_step_800d610c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bounds_800d60ac = 0x800d60ac;
hit_8043ae20 = 0x8043ae20;
splash_80388e58 = 0x80388e58;
trace_800b0824 = 0x800b0824;
value_80178df0 = 0x80178df0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27c_projectile_step_800d610c 0x800d610c : { *(.text.d27c_projectile_step_800d610c) }
  .rodata 0x80388e60 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; traceFrac_804b1764 = .;
    . = 0x24; svc_804b1788 = .;
    . = 0x44; stamp1_804b17a8 = .;
    . = 0x48; stamp0_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
