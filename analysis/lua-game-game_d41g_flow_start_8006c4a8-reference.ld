/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41g_flow_start_8006c4a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
arg_8015b410 = 0x8015b410;
args_8015c3ec = 0x8015c3ec;
as_80342a78 = 0x80342a78;
count_8015b424 = 0x8015b424;
data_803ebc18 = 0x803ebc18;
finish_8006eebc = 0x8006eebc;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
read_800fc1b0 = 0x800fc1b0;
read_str_800fc2b0 = 0x800fc2b0;
set_mode_8006ab48 = 0x8006ab48;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
suffix_8020c0fc = 0x8020c0fc;
upper_8020c2e8 = 0x8020c2e8;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d41g_flow_start_8006c4a8 0x8006c4a8 : { *(.text.d41g_flow_start_8006c4a8) }
  .rodata 0x8037bf80 : { *(.rodata) }
  .sdata 0x804aa840 (NOLOAD) : {
    . = 0x0; arg_804aa840 = .;
    . = 0x2e6c; c_804ad6ac = .;
    . = 0x2e74; c_804ad6b4 = .;
    . = 0x2e7c; c_804ad6bc = .;
    . = 0x2e84; c_804ad6c4 = .;
    . = 0x2e8c; c_804ad6cc = .;
    . = 0x2e94; c_804ad6d4 = .;
    . = 0x2e9c; c_804ad6dc = .;
    . = 0x2ea4; c_804ad6e4 = .;
    . = 0x2eac; c_804ad6ec = .;
    . = 0x2eb4; c_804ad6f4 = .;
    . = 0x2ebc; c_804ad6fc = .;
    . = 0x2ec4; c_804ad704 = .;
    . = 0x2ed4; c_804ad714 = .;
    . = 0x2edc; c_804ad71c = .;
    . = 0x2ee4; c_804ad724 = .;
    . = 0x2eec; c_804ad72c = .;
    . = 0x2ef4; c_804ad734 = .;
    . = 0x2f1c; c_804ad75c = .;
    . = 0x2f24; c_804ad764 = .;
    . = 0x2f2c; c_804ad76c = .;
    . = 0x2f44; c_804ad784 = .;
    . = 0x2f8c; c_804ad7cc = .;
    . = 0x2f94; c_804ad7d4 = .;
    . = 0x2f9c; c_804ad7dc = .;
    . = 0x2fa4; c_804ad7e4 = .;
    . = 0x2fac; c_804ad7ec = .;
    . = 0x2fec; c_804ad82c = .;
    . = 0x3024; c_804ad864 = .;
    . = 0x6f14; arena_804b1754 = .;
    . = 0x6f48; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
