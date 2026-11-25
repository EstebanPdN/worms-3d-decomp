/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_team_timer_tick_8021c144)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_8021e930 = 0x8021e930;
context_80165254 = 0x80165254;
key_8041aac8 = 0x8041aac8;
key_8041aae8 = 0x8041aae8;
lookup_8020b680 = 0x8020b680;
paused_8015ccbc = 0x8015ccbc;
prepare_8021e054 = 0x8021e054;
props_80240b84 = 0x80240b84;
value_8021eb00 = 0x8021eb00;
SECTIONS {
  .text.w3d_d26k_team_timer_tick_8021c144 0x8021c144 : { *(.text.w3d_d26k_team_timer_tick_8021c144) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
