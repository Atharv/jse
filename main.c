#include "JSNative.h"

int main(int argc, char *argv[], char *envp[]) {

	// we will be using main context group for the duration of runtime.
	JSContextGroupRef cgroup = JSContextGroupRetain(JSContextGroupCreate());
	JSContextRef ctx = JSGlobalContextRetain(JSGlobalContextCreateInGroup(cgroup, NULL));
	JSValueRef e = NULL;
	JSValueRef * exception = &e;

	js_native_init(ctx, argc, argv, envp, exception);
	
	if (argc) JSTRunScript(argv[1], RtJS(Global));

	if (JSTCaughtException) {
		JSTReportError("User script execution error");
		exit(1);
	}

}

