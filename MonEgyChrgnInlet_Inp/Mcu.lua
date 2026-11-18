local M = {}

function M.handler(name)
    if name:match("^SchM_Enter") ~= nil or name:match("^SchM_Exit") ~= nil then
        return {{
            action = "macro_def",
            name = name .. "()",
            value = "(void)0;"
        }}
    elseif name:match("^Mcu_Rb_GetSysTicks") then
        return {{
            action = "var_def",
            name = "_SYS_TICKS",
            value = "uint32 _SYS_TICKS;"
        }, {
            action = "var_decl",
            name = "_SYS_TICKS;",
            value = "extern uint32 _SYS_TICKS;"
        }, {
            action = "macro_def",
            name = name .. "()",
            value = "_SYS_TICKS"
        }}
    elseif name == "Mcu_Rb_GetSysTimePart" then
        return {{
            action = "macro_def",
            name = name .. "(x)",
            value = "(0)"
        }}
    elseif name == "RBA_OSSHELL_GET_INT_ID" then
        return {{
            action = "macro_def",
            name = name .. "(int_name)",
            value = "(0)"
        }}
    end
    return nil
end

return M
