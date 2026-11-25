/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_device_reset_802e0e84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e1730 = 0x802e1730;
fn_80304b84 = 0x80304b84;
w3d_auto_802e1720 = 0x802e1720;
w3d_disc_monitor_instance_800c8120 = 0x800c8120;
w3d_disc_set_flag1_800c7fe4 = 0x800c7fe4;
SECTIONS {
  .text.w3d_k6b_device_reset_802e0e84 0x802e0e84 : { *(.text.w3d_k6b_device_reset_802e0e84) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
