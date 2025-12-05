// src/App.js

import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './App.css';
import './banners.css'
import SongCard from './components/SongCard'; // <-- Imported SongCard component

// IMPORTANT: You must install and configure react-router-dom.
// Replace the placeholder Link below with: import { Link } from 'react-router-dom';
const Link = ({ to, children, className }) => <a href={to} className={className}>{children}</a>;


// --- FULL ACTIVITY DATA ARRAY (For the Sidebar) ---
const activityItems = [
    // All paths use the /r/ prefix and /r/ folder must be in public/
    { id: 1, main: "Nusrat Fateh Ali Khan", sub: "Artist", img: "/r/s1.jpg", href: "/artist/nfak" },
    { id: 2, main: "The Bends", sub: "Album . Radiohead", img: "/r/s2.jpg", href: "/album/thebends" },
    { id: 3, main: "Best of NFAK", sub: "Playlist . aksht", img: "/r/s3.jpg", href: "/playlist/nfakbest" },
    { id: 4, main: "Jeff Buckley", sub: "Artist", img: "/r/s4.png", href: "/artist/jeffbuckley" },
    { id: 5, main: "Grace", sub: "Album . Jeff Buckley", img: "/r/s5.jpg", href: "/album/grace" },
    { id: 6, main: "OK computer", sub: "Album . Radiohead", img: "/r/s6.jpg", href: "/album/okcomputer" },
    { id: 7, main: "Sinema", sub: "Album . Peter Cat Rec Company", img: "/r/s7.jpg", href: "/album/sinema" },
    { id: 8, main: "Bismillah", sub: "Album . Peter Cat Recording Company", img: "/r/s8.jpg", href: "/album/bismillah" },
    { id: 9, main: "French Exit", sub: "Album . TV Girl", img: "/r/s9.jpg", href: "/album/frenchexit" },
    { id: 10, main: "Divorced", sub: "Playlist . Akio.", img: "/r/s10.jpg", href: "/playlist/divorced" },
    { id: 11, main: "Jaanam", sub: "Album . Suryakant Sawhney", img: "/r/s11.jpg", href: "/album/jaanam" },
    { id: 12, main: "NeverMind", sub: "Album . Nirvana", img: "/r/s12.png", href: "/album/nevermind" },
    { id: 13, main: "Rockstar", sub: "Album . Mohit Chauhan , A.R Rehman", img: "/r/s13.jpg", href: "/album/rockstar" }
];
// ----------------------------------------------------------------------


function App() {
  // Removed unused 'count' state and logic
  
  return (
    <>
      {/* --- Navbar Section (className applied, Link used) --- */}
      <div className="navbar">
        <div className="nav-left">
          <Link to="/" className="main_logo"> 
            <img src="/r/mikuu.png" className="melody2_img" alt="Spicify Logo" /> Spicify
          </Link>
        </div>
        
        <label className="search-label">
          <input type="text" name="text" className="input" required="" placeholder="Search Your Music..." />
          <kbd className="slash-icon">/</kbd>
          <svg className="search-icon" xmlns="http://www.w3.org/2000/svg" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" width="512" height="512" x="0" y="0" viewBox="0 0 56.966 56.966" style={{ enableBackground: 'new 0 0 512 512' }} xmlSpace="preserve">
            <g>
              <path d="M55.146 51.887 41.588 37.786A22.926 22.926 0 0 0 46.984 23c0-12.682-10.318-23-23-23s-23 10.318-23 23 10.318 23 23 23c4.761 0 9.298-1.436 13.177-4.162l13.661 14.208c.571.593 1.339.92 2.162.92.779 0 1.518-.297 2.079-.837a3.004 3.004 0 0 0 .083-4.242zM23.984 6c9.374 0 17 7.626 17 17s-7.626 17-17 17-17-7.626-17-17 7.626-17 17-17z" fill="currentColor"></path>
            </g>
          </svg>
        </label>

        <div className="nav-right">
          <Link to="/">
            <img src="/r/home icon.png" className="melody_img" alt="Home" />Home
          </Link>
          <Link to="/profile">
            <img src="/r/contact.png" className="melody_img" alt="Profile" />Profile
          </Link>
        </div>
      </div>
      <hr />

      {/* --- Main View --- */}
      <div className="mainpageview">

        {/* --- Activity Sidebar (Refactored to use map) --- */}
        <div className="mainleft">
          <div>
            <a className="leftheadtext">Your Activity</a> <br />
            <hr />
          </div>
          <div className="activity-scroll">
            {/* Renders the full list using the SongCard component */}
            {activityItems.map(item => (
                <SongCard
                    key={item.id}
                    imgSrc={item.img}
                    mainText={item.main}
                    subText={item.sub}
                    linkTo={item.href}
                />
            ))}
            <br/><br/><br/><br/>
          </div>
        </div>

        {/* --- Main Content / Posters (Needs Refactoring, Paths Corrected) --- */}
        <div className="mainright">
          
          {/* TV Girl Section */}
          <a className="headtext">
            <img src="/r/tvgirlfav.jpg" className="fav" alt="TV Girl favorite" /> TV Girl....
          </a>
          <div className="posters">
            <Link to="/album/queen"><img src="/r/r1p2.jpg" className="posterL" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/r1p1.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r1p3.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r1p4.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r1p5.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/tvpfp.jpg" className="poster2" alt="Profile Picture" /></Link>
          </div>
          
          {/* Radiohead Section */}
          <a className="headtext">
            <img src="/r/rdhdfav.jpg" className="fav" alt="Radiohead favorite" /> Radiohead....
          </a>
          <div className="posters">
            <Link to="/album/queen"><img src="/r/r2p1.jpg" className="posterL" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r2c2.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r1c3.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r2p7.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r2p8.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/r1c1.jpg" className="poster2" alt="Poster" /></Link>
          </div>
          
          {/* Umbrella Rock Section */}
          <a className="headtext">
            <img src="/r/image.png" className="fav" alt="Umbrella Rock favorite" /> Umbrella Rock....
          </a>
          <div className="posters">
            <Link to="/album/queen"><img src="/r/r3p1.jpg" className="posterL" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r3p4.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r3p3.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r3p5.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r3p2.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/jeffpfp.png" className="poster2" alt="Profile Picture" /></Link>
          </div>
          
          {/* Bhartiya Sangeet Section (Repeated sections cleaned up) */}
          <a className="headtext">
            <img src="/r/rockfav.jpg" className="fav" alt="Rock favorite" /> Bhartiya Sangeet....
          </a>
          <div className="posters">
            <Link to="/album/queen"><img src="/r/r4p5.jpg" className="posterL" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r4p2.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r4p4.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r4p6.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r4p1.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/r4c.jpg" className="poster2" alt="Poster" /></Link>
          </div>

          <a className="headtext">
            <img src="/r/rockfav.jpg" className="fav" alt="Rock favorite" /> Oh no i dropped my feminist literature....
          </a>
          <div className="posters">
            <Link to="/album/queen"><img src="/r/r5p1.jpg" className="posterL" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r5p5.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r5p2.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r5p3.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/queen"><img src="/r/r5p4.jpg" className="poster3" alt="Poster" /></Link>
            <Link to="/album/radiohead"><img src="/r/clairopfp.jpg" className="poster2" alt="Profile Picture" /></Link>
          </div>

          {/* ... The rest of the duplicated Bhartiya Sangeet sections are removed for brevity ... */}

          <br/><br/><br/><br/>
        </div>
      </div>
      <hr />
      
    </>
  );
}

export default App;