/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(abort)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_exit = 0x802f3c6c;
vfiprintf = 0x802f1cb8;
w3d_auto_802e3294 = 0x802e3294;
w3d_vfiprintf_console_buffer_8047dc9c = 0x8047dc9c;
w3d_vfprintf_console_buffer_8047dc1c = 0x8047dc1c;
SECTIONS {
  .text.abort 0x802ed798 : { *(.text.abort) }
  .text.exit 0x802ed984 : { *(.text.exit) }
  .text.w3d_vfprintf_console_write_802f05f0 0x802f05f0 : { *(.text.w3d_vfprintf_console_write_802f05f0) }
  .text.w3d_vfiprintf_console_write_802f1be0 0x802f1be0 : { *(.text.w3d_vfiprintf_console_write_802f1be0) }
  .text.fiprintf 0x802f3434 : { *(.text.fiprintf) }
  .text.w3d_abort_forward_802f4ddc 0x802f4ddc : { *(.text.w3d_abort_forward_802f4ddc) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . = 0x10; w3d_sda_vfprintf_console_count_804ac580 = .;
    . = 0x14; w3d_sda_vfprintf_console_size_804ac584 = .;
    . = 0x18; w3d_sda_vfprintf_console_next_804ac588 = .;
    . = 0x1c; w3d_sda_vfiprintf_console_count_804ac58c = .;
    . = 0x20; w3d_sda_vfiprintf_console_size_804ac590 = .;
    . = 0x24; w3d_sda_vfiprintf_console_next_804ac594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
