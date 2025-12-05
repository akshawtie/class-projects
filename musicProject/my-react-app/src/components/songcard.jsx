// src/components/SongCard.jsx

import React from 'react';
// IMPORTANT: You must install and configure react-router-dom 
// and import 'Link' here: import { Link } from 'react-router-dom';

// Placeholder Link until you install the router:
const Link = ({ to, children, className }) => <a href={to} className={className}>{children}</a>;


const SongCard = ({ imgSrc, mainText, subText, linkTo }) => {
  return (
    <div className="songcard">
      <img src={imgSrc} className="songimg" alt={mainText} />
      <div className="textblock">
        <p className="maintext">{mainText}</p>
        {/* We use a React Fragment <> </> because the subtext sometimes contains an <a> tag */}
        <p className="subtext">
          {/* Note: The subtext might contain another link, which we leave as an <a> for simplicity */}
          <Link to={linkTo}>{subText}</Link> 
        </p>
      </div>
    </div>
  );
};

export default SongCard;