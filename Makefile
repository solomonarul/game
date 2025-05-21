.PHONY: all

r: rd

c:
	@cmake -E remove_directory build
	@cmake -E remove_directory out*
	@echo "[INFO]: Cleaning complete."

bd:
	@echo "[INFO]: Building in Debug mode..."
	@cmake -E make_directory build/debug
	@((cmake -S . --preset debug > build/debug/configure.log 2>&1) || \
		(cat build/debug/configure.log && echo "[EROR]: An error occured during configuring! Stopping..." && false))
	@((cmake --build --preset debug > build/debug/build.log 2>&1) || \
		(cat build/debug/build.log && echo "[EROR]: An error occured during building! Stopping..." && false))
	@((cmake --install build/debug --prefix out/debug > build/debug/install.log 2>&1) || \
		(cat build/debug/install.log && echo "[EROR]: An error occured during installing! Stopping..." && false))

br:
	@echo "[INFO]: Building in Release mode..."
	@cmake -E make_directory build/release
	@((cmake -S . --preset release > build/release/configure.log 2>&1) || \
		(cat build/release/configure.log && echo "[EROR]: An error occured during configuring! Stopping..." && false))
	@((cmake --build --preset release > build/release/build.log 2>&1) || \
		(cat build/release/build.log && echo "[EROR]: An error occured during building! Stopping..." && false))
	@((cmake --install build/release --prefix out/release > build/release/install.log 2>&1) || \
		(cat build/release/install.log && echo "[EROR]: An error occured during installing! Stopping..." && false))

b: bd

rd:
	@./out/debug/bin/game

rr:
	@./out/release/bin/game