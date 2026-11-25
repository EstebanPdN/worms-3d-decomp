/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_service_result_append_8008bffc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
interface_key_80410bc8 = 0x80410bc8;
interface_lookup_8020b680 = 0x8020b680;
service_create_80164514 = 0x80164514;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_service_result_append_8008bffc 0x8008bffc : { *(.text.w3d_cx9a_service_result_append_8008bffc) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
