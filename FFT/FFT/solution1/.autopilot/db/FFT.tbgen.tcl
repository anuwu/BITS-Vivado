set moduleName FFT
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {FFT}
set C_modelType { void 0 }
set C_modelArgList {
	{ data_IN int 32 regular {axi_s 0 volatile  { data_IN Data } }  }
	{ data_OUT int 32 regular {axi_s 1 volatile  { data_OUT Data } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "data_IN", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "data_IN._M_real.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]},{"low":16,"up":31,"cElement": [{"cName": "data_IN._M_imag.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]}]} , 
 	{ "Name" : "data_OUT", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "data_OUT._M_real.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]},{"low":16,"up":31,"cElement": [{"cName": "data_OUT._M_imag.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 12
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ data_IN_TDATA sc_in sc_lv 32 signal 0 } 
	{ data_IN_TVALID sc_in sc_logic 1 invld 0 } 
	{ data_IN_TREADY sc_out sc_logic 1 inacc 0 } 
	{ data_OUT_TDATA sc_out sc_lv 32 signal 1 } 
	{ data_OUT_TVALID sc_out sc_logic 1 outvld 1 } 
	{ data_OUT_TREADY sc_in sc_logic 1 outacc 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "data_IN_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data_IN", "role": "TDATA" }} , 
 	{ "name": "data_IN_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "data_IN", "role": "TVALID" }} , 
 	{ "name": "data_IN_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "data_IN", "role": "TREADY" }} , 
 	{ "name": "data_OUT_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data_OUT", "role": "TDATA" }} , 
 	{ "name": "data_OUT_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "data_OUT", "role": "TVALID" }} , 
 	{ "name": "data_OUT_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "data_OUT", "role": "TREADY" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "23", "24"],
		"CDFG" : "FFT",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "561", "EstimateLatencyMax" : "561",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state6", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_FFT0_fu_261"},
			{"State" : "ap_ST_fsm_state8", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_FFT0_fu_261"},
			{"State" : "ap_ST_fsm_state10", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_FFT0_fu_261"},
			{"State" : "ap_ST_fsm_state12", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_FFT0_fu_261"},
			{"State" : "ap_ST_fsm_state14", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_FFT0_fu_261"}],
		"Port" : [
			{"Name" : "data_IN", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "data_IN_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "data_OUT", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "data_OUT_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "xin_M_real_V", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "xin_M_imag_V", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "rev_32", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "data_OUT0_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_real_V"}]},
			{"Name" : "data_OUT0_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_imag_V"}]},
			{"Name" : "W_M_real_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "W_M_real_V"}]},
			{"Name" : "W_M_imag_V", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "W_M_imag_V"}]},
			{"Name" : "data_OUT1_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_real_V"}]},
			{"Name" : "data_OUT1_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_imag_V"}]},
			{"Name" : "data_OUT2_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_real_V"}]},
			{"Name" : "data_OUT2_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_imag_V"}]},
			{"Name" : "data_OUT3_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_real_V"}]},
			{"Name" : "data_OUT3_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_imag_V"}]},
			{"Name" : "data_OUT4_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_real_V"}]},
			{"Name" : "data_OUT4_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_IN_M_imag_V"}]},
			{"Name" : "xout_M_real_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_OUT_M_real_V"}]},
			{"Name" : "xout_M_imag_V", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_FFT0_fu_261", "Port" : "data_OUT_M_imag_V"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.xin_M_real_V_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.xin_M_imag_V_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rev_32_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT0_M_real_V_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT0_M_imag_V_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT1_M_real_V_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT1_M_imag_V_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT2_M_real_V_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT2_M_imag_V_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT3_M_real_V_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT3_M_imag_V_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT4_M_real_V_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.data_OUT4_M_imag_V_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.xout_M_real_V_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.xout_M_imag_V_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261", "Parent" : "0", "Child" : ["17", "18", "19", "20", "21", "22"],
		"CDFG" : "FFT0",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "65", "EstimateLatencyMax" : "65",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "FFT_stage", "Type" : "None", "Direction" : "I"},
			{"Name" : "pass_check", "Type" : "None", "Direction" : "I"},
			{"Name" : "index_shift", "Type" : "None", "Direction" : "I"},
			{"Name" : "pass_shift", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_IN_M_real_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "data_IN_M_imag_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "data_OUT_M_real_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "data_OUT_M_imag_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "W_M_real_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "W_M_imag_V", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.W_M_real_V_U", "Parent" : "16"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.W_M_imag_V_U", "Parent" : "16"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.FFT_mul_mul_10s_1bkb_U1", "Parent" : "16"},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.FFT_mul_mul_16s_9cud_U2", "Parent" : "16"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.FFT_mac_mulsub_9sdEe_U3", "Parent" : "16"},
	{"ID" : "22", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_FFT0_fu_261.FFT_mac_muladd_10eOg_U4", "Parent" : "16"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_IN_U", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_OUT_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	FFT {
		data_IN {Type I LastRead 1 FirstWrite -1}
		data_OUT {Type O LastRead -1 FirstWrite 13}
		xin_M_real_V {Type IO LastRead -1 FirstWrite -1}
		xin_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		rev_32 {Type I LastRead -1 FirstWrite -1}
		data_OUT0_M_real_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT0_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		W_M_real_V {Type I LastRead -1 FirstWrite -1}
		W_M_imag_V {Type I LastRead -1 FirstWrite -1}
		data_OUT1_M_real_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT1_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT2_M_real_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT2_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT3_M_real_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT3_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT4_M_real_V {Type IO LastRead -1 FirstWrite -1}
		data_OUT4_M_imag_V {Type IO LastRead -1 FirstWrite -1}
		xout_M_real_V {Type IO LastRead -1 FirstWrite -1}
		xout_M_imag_V {Type IO LastRead -1 FirstWrite -1}}
	FFT0 {
		FFT_stage {Type I LastRead 0 FirstWrite -1}
		pass_check {Type I LastRead 0 FirstWrite -1}
		index_shift {Type I LastRead 0 FirstWrite -1}
		pass_shift {Type I LastRead 0 FirstWrite -1}
		data_IN_M_real_V {Type I LastRead 2 FirstWrite -1}
		data_IN_M_imag_V {Type I LastRead 2 FirstWrite -1}
		data_OUT_M_real_V {Type O LastRead -1 FirstWrite 3}
		data_OUT_M_imag_V {Type O LastRead -1 FirstWrite 3}
		W_M_real_V {Type I LastRead -1 FirstWrite -1}
		W_M_imag_V {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "561", "Max" : "561"}
	, {"Name" : "Interval", "Min" : "562", "Max" : "562"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	data_IN { axis {  { data_IN_TDATA in_data 0 32 }  { data_IN_TVALID in_vld 0 1 }  { data_IN_TREADY in_acc 1 1 } } }
	data_OUT { axis {  { data_OUT_TDATA out_data 1 32 }  { data_OUT_TVALID out_vld 1 1 }  { data_OUT_TREADY out_acc 0 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
