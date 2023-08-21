const signUp = require("../models/signUpModel")
const insertUser = async(req, res)=>{
    console.log(req.session)
    try{
        const user = new signUp({
            name: req.body.name,
            email: req.body.email,
            phone: req.body.phone,
            birthday: req.body.birthday,
            gender: req.body.gender,
            password: req.body.password,
        })
        const result = await user.save()
        res.redirect('/')
    }
    catch(err){
        res.redirect('signup')
    }
}

module.exports = {insertUser}