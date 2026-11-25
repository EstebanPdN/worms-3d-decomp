/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40c_message_handler_800fda04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8016293c = 0x8016293c;
forward_800fdc80 = 0x800fdc80;
id_equals_8015f65c = 0x8015f65c;
k_80398144 = 0x80398144;
motion_800668fc = 0x800668fc;
start_800fdc34 = 0x800fdc34;
stop_800fdc7c = 0x800fdc7c;
velocity_800668b8 = 0x800668b8;
SECTIONS {
  .text.d40c_message_handler_800fda04 0x800fda04 : { *(.text.d40c_message_handler_800fda04) }
  .sdata 0x804af13c (NOLOAD) : {
    . = 0x0; cache_804af13c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
