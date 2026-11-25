/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_w1_script_start_80100490)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
as_80343744 = 0x80343744;
build_8010391c = 0x8010391c;
call_801036f0 = 0x801036f0;
fail_803987c8 = 0x803987c8;
flag_802ccb00 = 0x802ccb00;
fn_80100748 = 0x80100748;
fn_8010273c = 0x8010273c;
init_803987e8 = 0x803987e8;
message_id_8015f5a0 = 0x8015f5a0;
msg_init_8010a8e0 = 0x8010a8e0;
n1_80398770 = 0x80398770;
n2_80398788 = 0x80398788;
n3_8039879c = 0x8039879c;
n4_803987b0 = 0x803987b0;
post_8016239c = 0x8016239c;
read_800fc1b0 = 0x800fc1b0;
set_run_8010272c = 0x8010272c;
sub_801037a8 = 0x801037a8;
SECTIONS {
  .text.d24c_w1_script_start_80100490 0x80100490 : { *(.text.d24c_w1_script_start_80100490) }
  .sdata 0x804aaf88 (NOLOAD) : {
    . = 0x0; flag_804aaf88 = .;
    . = 0x41dc; cache_804af164 = .;
    . = 0x67cc; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
