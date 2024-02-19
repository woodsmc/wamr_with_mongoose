# A Web Server in WebAssembly with Mongoose and WAMR
This project contains a Mongoose custom header which allows you to build Mongoose applications for the [Wasm Micro Runtime (WAMR)](https://github.com/bytecodealliance/wasm-micro-runtime).

## Building The Server

## Building the Execution Environment
You need to build WAMR with networking and socket support.

### Build WAMR with pthread and socket support

### Executing WAMR 
When you execute WAMR you have to tell it at the command line what permissions you will grant the running WebAssembly code. For the example WebServer to work you will need to provide the following command line switches:

```
./iwasm --dir=. --addr-pool=127.0.0.1/15 <wasm file name to execute>
```
