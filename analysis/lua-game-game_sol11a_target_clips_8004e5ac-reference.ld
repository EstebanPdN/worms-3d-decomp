/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol11a_target_clips_8004e5ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
check_8018179c = 0x8018179c;
no_target_803777b8 = 0x803777b8;
play_80181640 = 0x80181640;
ready_8004e324 = 0x8004e324;
scale_8004e544 = 0x8004e544;
stop_801817e0 = 0x801817e0;
SECTIONS {
  .text.sol11a_target_clips_8004e5ac 0x8004e5ac : { *(.text.sol11a_target_clips_8004e5ac) }
  .rodata 0x803777c8 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
