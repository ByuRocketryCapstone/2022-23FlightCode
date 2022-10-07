mainTick() {
    //state update, Mealy actions
    switch (CurrState) {
    case init_st:
        break;

    case wait_arm_st:
        break;

    case arm_st:
        break;

    case ignition_st:
        break;

    case wait_cutoff_st:
        break;

    case update_st:
        break;

    case control_st:
        break;

    case log_st:
        break;

    case at_apogee_st:
        break;

    case retract_st:
        break;

    case descent_st:
        break;

    case done_st:
        break;

    default:
        break;

    }

    //update state
    CurrState = NextState;

    //state action, Moore actions
    switch (CurrState) {
    case init_st:
        break;

    case wait_arm_st:
        break;

    case arm_st:
        break;

    case ignition_st:
        break;

    case wait_cutoff_st:
        break;

    case update_st:
        break;

    case control_st:
        break;

    case log_st:
        break;

    case at_apogee_st:
        break;

    case retract_st:
        break;

    case descent_st:
        break;

    case done_st:
        break;

    default:
        break;

    }
}