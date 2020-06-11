<project xmlns="com.autoesl.autopilot.project" top="forward" name="DigitRecognizer">
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="100">
        <SimFlow name="csim" ldflags="" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../minibatch_tp.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" 100 -Wno-unknown-pragmas" blackbox="false"/>
        <file name="DigitRecognizer/minibatch.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

