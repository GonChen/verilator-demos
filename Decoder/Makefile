run: obj_dir/VDecoder
	obj_dir/VDecoder | head

obj_dir/VDecoder: Decoder.v Decoder-harness.cpp
	verilator -Wall --cc Decoder.v --trace --exe Decoder-harness.cpp
	make -C obj_dir -j -f VDecoder.mk VDecoder
