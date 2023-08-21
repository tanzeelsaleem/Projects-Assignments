const express = require('express')
const bodyParser = require('body-parser')
const mongoose = require("mongoose")
const session = require('express-session');
const signUp = require('./controller/signUpController')

mongoose.set('strictQuery', false)
mongoose.connect("mongodb://127.0.0.1:27017/emart").then(() => {
    console.log("Connection Established!")
}).catch((err) => {
    console.log(err)
})

const app = express()

app.use('/static', express.static('./static'))
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(session({
    secret: 'my-secret',  // Use a secret string to sign the session ID cookie
    resave: false,
    saveUninitialized: true
}));

const userModel = mongoose.model('signups', {
    email: String,
    password: String
})

const historyModel = mongoose.model('history',
    { user: String, name: String, type: String, date: String, link: String }
);

const prod = mongoose.model('products', {
    name: String,
    price: Number,
    category: String,
    ratings: Number,
    stars: Number,
    image: String
})

app.set('view engine', 'pug')
app.set('views', 'views')
app.get("/", (req, res) => {
    user = req.session.user
    prod.find((error, products) => {
        if (products) {
            if (user) {
                res.render('index', { products: products, sess: 1 })
            }
            else
                res.render('index', { products: products })
        }
    })
})

app.get("/login", (req, res) => {
    user = req.session.user
    if (user) {
        res.redirect('/')
    }
    else
        res.render('login')
})

app.get("/logout", (req, res) => {
    req.session.user = null
    res.redirect('/')
})

app.get("/signup", (req, res) => {
    user = req.session.user
    if (user) {
        res.redirect('/')
    }
    else
        res.render('signup')
})

app.get("/about", (req, res) => {
    res.render('about')
})

app.get("/contact", (req, res) => {
    user = req.session.user
    if (user) {
        res.render('contact', { sess: 1 })
    }
    else
        res.render('contact')
})

app.get("/cart", (req, res) => {
    _user = req.session.user
    if (user) {
        historyModel.find({
            user: _user
        }, (error, products) => {
            if (products) {
                console.log(products)
                res.render('cart', { products: products, sess:1 })
            }
        })    
    }
    else
        res.redirect('/login')
})

app.get('/products', (req, res) => {
    cat = req.query.q;
    prod.find({
        category: cat
    }, (error, products) => {
        if (products) {
            res.render('products', { products: products })
        }
    })
})

app.get('/search',(req,res)=>{
    _name = req.query.name;
    _name = _name.toLowerCase()
    console.log(_name)
    prod.find((error, products) => {
        if (products) {
            np = []
            for(let i=0; i<products.length; i++){
                n = products[i].name.toLowerCase()
                if(n.includes(_name)){
                    np.push(products[i])
                }
            }
            res.render('search', { products: np, query:_name })
        }
    })
})

app.post('/signupAction', signUp.insertUser)

app.post('/loginAction', (req, res) => {
    userModel.findOne({
        email: req.body.email,
        password: req.body.password,
    }, (error, user) => {
        if (error) {
            res.sendStatus(500);
        } else if (user) {
            req.session.user = user.email;
            res.redirect('/');
        } else {
            u = {
                email: req.body.email,
                password: req.body.password
            }
            res.render('login', { error: 'Invalid email or password', user: u });
        }
    });
});

app.get('/buy', (req, res) => {
    let _name = req.query.name
    prod.findOne({ name: _name }, (error, doc) => {
        if (error) {
            console.log(error);
        }
        else {
            user = req.session.user
            if (user) {
                res.render('product', { obj: doc, sess: 1 })
            }
            else
                res.render('product', { obj: doc })
        }
    });

})

app.get('/history', (req, res) => {
    user = req.session.user
    if (user) {
        let name = req.query.name
        const example = new historyModel({ user: user, name: name, type: 'order', date: new Date().toJSON().slice(0, 10), link: '/buy?name=' + name });
        example.save((error) => {
            if (error) {
                console.log(error);
            }
        });
        res.redirect('/cart')
    }
    else
        res.render('login')
});

app.get('/history_cart', (req, res) => {
    user = req.session.user
    if (user) {
        let name = req.query.name
        const example = new historyModel({ user: user, name: name, type: 'cart', date: new Date().toJSON().slice(0, 10), link: '/buy?name=' + name });
        example.save((error) => {
            if (error) {
                console.log(error);
            }
        });
        res.redirect('/cart')
    }
    else
        res.render('login')
});


app.listen(8888, () => {
    console.log('Listening to port 8888...')
})