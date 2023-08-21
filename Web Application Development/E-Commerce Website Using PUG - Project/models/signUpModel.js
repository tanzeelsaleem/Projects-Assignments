const mongoose = require('mongoose')

const signUp = mongoose.Schema({
    name:{
        type: String,
        required: true,
        validate(val){
            let regex = /^[a-zA-Z]+$/
            if(!regex.test(val)){
                throw new Error("Numbers are not Allowed!");
                
            }
        }
    },
    email:{
        type: String,
        unique: true,
        required: true,
        validate(val){
            let regex = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$/
            if(!regex.test(val)){
                throw new Error("Email format should be: abc@example.com");
            }
        }
    },
    phone:{
        type: String,
        required: true,
        validate(val){
            let regex = /^03[0-9]{2}[0-9]{7}$/
            if(!regex.test(val)){
                throw new Error("Phone Number format should be: 03XXXXXXX");
            }
        }
    },
    birthday:{
        type: String,
        required: true,
    },
    gender:{
        type: String,
        enum: ['male', 'female','other']
    },
    password:{
        type: String,
        required: true,
        validate(val){
            let regex = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/
            if(!regex.test(val)){
                throw new Error("Password must contain minimum 8 characters, at least one letter and one number!");
            }
        }
    },
})
const signUpSchema = mongoose.model("signUp", signUp)
module.exports = signUpSchema;